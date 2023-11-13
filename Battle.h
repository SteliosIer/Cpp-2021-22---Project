#pragma once
#include "Battle.h"
#include "graphics.h"
#include "confi.h"
#include <list>
#include "Card.h"
using namespace graphics;


class Battle {

	typedef enum {STATUS_START,STATUS_INFO,STATUS_PLAYING, STATUS_CPU_PLAYING, STATUS_PICKING_CARD, STATUS_ENDGAME} status_t;
	static Battle* m_instance;
	std::list<Card*> m_cards;
	std::list<Card*> cpuCards;
	std::list<Card*> cards_remain;
	Battle();
	status_t status = STATUS_START;

public:

	
	void draw();
	void update();

	//general methods
	void font();
	void drawbackground();
	void drawHero(Card * hero, float x, float y, std::string(link));
	void drawCards(bool showPower, Card * c, int x, float i, float j, float numberofcards);
	void setPowers();

	//INFO 
	void drawinfobutton();
	void updateinfobutton();
	void drawInfo();
	void updateInfoScreen();
	void drawExitInfo();


	//START SCREEN
	void updateStartScreen();
	void drawStartScreen();	
	void drawAllCards();
	void drawStartingText();
	

	//PLAYING SCREEN
	void updatePlayingScreen();
	void drawPlayingScreen();
	void drawBattleScreen();
	void drawPlayingText();
	void drawPlayerCards();
	void drawCpuCards();


	//CPU PLAYING SCREEN
	void drawCpuPlayingScreen();
	void updateCpuPlayingScreen();
	void drawCpuPlayingCards();

	//PICKING CARD SCREEN
	void drawPickingScreen();
	void updatePickingCard();
	void drawRestOfPlayerCards();
	void drawTextForWinner();

	//ENDGAME
	void QuitGame();
	void drawGameOver();


	~Battle(); 
	static Battle* getInstance();
	static void releaseInstance();
	
};