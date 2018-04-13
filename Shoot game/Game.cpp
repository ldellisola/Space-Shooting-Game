#include "Game.h"



Game::Game(const char * bla)
{
	this->background = al_load_bitmap(bla);
	al_draw_bitmap(this->background, 0, 0, 0);
}


Game::~Game()
{
	delete this->shooter;
	delete this->target;
	delete this->score;
	delete this->menu;
	this->minions.clear();

	al_destroy_bitmap(this->background);
}

void Game::update()
{

	if (!shooter->bulletIsActive())
		shooter->bulletStartOver();
	else
		if (target->collision(shooter->bulletGetTopLeftX(), shooter->bulletGetTopLeftY(), shooter->bulletGetBotRightX(), shooter->bulletGetBotRightY()))
		{
			shooter->bulletStartOver();
			score->updateScore();

			if (!(score->getScore() % HITSPERLEVEL))
				Level.newLevel();
		}
		else
		{
			bool reset = false;
			for (int i = 0; !reset && i < minions.size(); ++i)
			{
				if (minions[i].collision(shooter->bulletGetTopLeftX(), shooter->bulletGetTopLeftY(), shooter->bulletGetBotRightX(), shooter->bulletGetBotRightY()))
				{
 					shooter->bulletStartOver();
					score->reset();
					minions.clear();
					Level.number = 1;
					addMinion(*this->dataMN);
					reset = true;
					Level.gameMenu = true;
					
					Level.newLevelAchieved = false;
					this->drawMenu();
					al_flip_display();
				}

			}
		}
	if (Level.newLevelAchieved)
	{
		addMinion();
		for (Target& minion : minions)
			minion.init();			// This is crap and it will eventually affect my program, but i don't think i'll have enought drones to fuck this up
		Level.newLevelAchieved = false;
	}
	if (!Level.gameMenu)
	{
		this->shooter->update();
		this->target->update();

		for (Target& minion : minions)
		{
			minion.setMovement();
			minion.update();
		}
	}

}

void Game::draw()
{
	al_draw_bitmap(this->background, 0, 0, 0);

	this->shooter->draw();
	this->target->draw();
	this->score->draw();

	for (Target& minion : this->minions)
		minion.draw();

	if (Level.gameMenu)
		this->menu->draw();
}

void Game::drawMenu()
{
	this->menu->draw();
}

void Game::setUpShooter(shooterData& dataS, bulletData& dataB)
{
	this->shooter = new Shooter (dataS.x, dataS.y, dataS.sprite, dataS.speed, dataS.displayW, dataS.displayH);
	shooter->init();
	shooter->createBullet(dataB.sprite, dataB.xSpeed, dataB.ySpeed);
}

void Game::addMinion(targetData& dataT)
{
	this->dataMN = &dataT;
	addMinion();
}

void Game::addMinion()
{
	this->minions.push_back(Target(dataMN->x, dataMN->y + dataMN->newOffset * (this->Level.number - 1), dataMN->speed + 2 * Level.number, dataMN->displayW, dataMN->displayH, dataMN->sprite));

	for (Target& minion : this->minions)
		minion.init();
}

void Game::setUpTarget(targetData& dataT)
{
	this->target = new Target(dataT.x, dataT.y, dataT.speed, dataT.displayW, dataT.displayH, dataT.sprite);
	target->init();
}

void Game::setUpScoreboard(textData& dataSB)
{
	this->score = new ScoreBoard(dataSB.x, dataSB.y, dataSB.width, dataSB.height, dataSB.fontSize, dataSB.text, dataSB.path, dataSB.color,"score.txt");
}

void Game::setUpStartboard(textData& dataSB)
{
	this->menu = new StartBoard(dataSB.x, dataSB.y, dataSB.width, dataSB.height, dataSB.fontSize, dataSB.text, dataSB.path, dataSB.color);

}

void Game::shoot()
{

	if (!Level.gameMenu)
	{
		if (!shooter->bulletIsActive())
			shooter->bulletFire();
	}
	else
		Level.gameMenu = false;
}
