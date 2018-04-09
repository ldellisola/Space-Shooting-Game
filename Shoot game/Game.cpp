#include "Game.h"



Game::Game()
{
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
	this->shooter->update();
	this->target->update();

	for (Target& minion : this->minions)
		minion.update();
}

void Game::draw()
{
	al_draw_bitmap(this->background, 0, 0, 0);

	this->shooter->draw();
	this->target->draw();
	this->score->draw();

	for (Target& minion : this->minions)
		minion.draw();
}

void Game::setUpShooter(shooterData& dataS, bulletData& dataB)
{
	this->shooter = new Shooter (dataS.x, dataS.y, dataS.sprite, dataS.speed, dataS.displayW, dataS.displayH);
	shooter->init();
	shooter->createBullet(dataB.sprite, dataB.xSpeed, dataB.ySpeed);
}

void Game::addMinion(targetData& dataT)
{
	int size = this->minions.size();
	this->minions.push_back(Target(dataT.x, dataT.y, dataT.speed, dataT.displayW, dataT.displayH, dataT.sprite));
	
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
	this->score = new ScoreBoard(dataSB.x, dataSB.y, dataSB.width, dataSB.height, dataSB.height, dataSB.text, dataSB.path, dataSB.color);
}

void Game::setUpStartboard(textData& dataSB)
{
	this->menu = new StartBoard(dataSB.x, dataSB.y, dataSB.width, dataSB.height, dataSB.height, dataSB.text, dataSB.path, dataSB.color);

}