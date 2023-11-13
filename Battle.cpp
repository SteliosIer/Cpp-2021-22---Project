#include "Battle.h"
#include "graphics.h"
#include "confi.h"
#include <list>
#include <cstdlib>
#include <time.h>
using namespace graphics;

Card* captain = new Card();
Card* hulk = new Card();
Card* thor = new Card();
Card* flash = new Card();
Card* spidey = new Card();
Card* ironman = new Card();
Card* wonder = new Card();
Card* superman = new Card();
Card* batman = new Card();
Card* wolvie = new Card();
Card* cardflip = new Card();

Card* CpuCardSelected = new Card();
Card* PlayerCardSelected = new Card();
int cardsSelected = 0;
int numberOfCpuCards;

void Battle::update()
{
	if (status == STATUS_START)
	{
		updateinfobutton();
		updateStartScreen();
		setPowers();
	}

	if (status == STATUS_INFO)
	{
		updateInfoScreen();
	}

	if (status == STATUS_PLAYING)
	{
		updatePlayingScreen();
	}

	if (status == STATUS_CPU_PLAYING)
	{
		updateCpuPlayingScreen();
	}

	if (status == STATUS_PICKING_CARD)
	{
		updatePickingCard();
	}

	if (status == STATUS_ENDGAME)
	{
		QuitGame();
	}
}


void Battle::draw()
{
	drawbackground();

	if (status == STATUS_START)
	{
		drawStartScreen();
	}

	if (status == STATUS_INFO)
	{
		drawInfo();
		drawExitInfo();
	}

	if (status == STATUS_PLAYING)
	{
		drawBattleScreen();
	}

	if (status == STATUS_CPU_PLAYING)
	{
		drawCpuPlayingScreen();
	}

	if (status == STATUS_PICKING_CARD)
	{
		drawPickingScreen();
	}

	if (status == STATUS_ENDGAME)
	{
		drawGameOver();
	}
}


//general methods


void Battle::font()
{
	setFont(std::string(ASSET_PATH) + "HOMOARAK.ttf");
}

void Battle::drawbackground()
{
	Brush br;
	br.texture = std::string(ASSET_PATH) + "background.png";
	br.outline_opacity = 0.0f;
	drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
}

void Battle::drawHero(Card * hero , float x, float y, std::string(link))
{
	hero->setPosX(x);
	hero->setPosY(y);
	hero->draw(link, x , y , CARD_SIZE / 1.5f, CARD_SIZE);
}

void Battle::drawCards(bool showPower, Card* c, int x, float i, float j, float numberofcards)
{
	if (showPower == true)
	{
		if (c == captain)
		{
			drawHero(captain, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\CAPTAIN.png");
		}
		if (c == hulk)
		{
			drawHero(hulk, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\HULK.png");
		}
		if (c == flash)
		{
			drawHero(flash, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\FLASH.png");
		}
		if (c == thor)
		{
			drawHero(thor, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\THOR.png");
		}
		if (c == wolvie)
		{
			drawHero(wolvie, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\WOLVIE.png");
		}
		if (c == spidey)
		{
			drawHero(spidey, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\SPIDEY.png");
		}
		if (c == ironman)
		{
			drawHero(ironman, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\IRONMAN.png");
		}
		if (c == wonder)
		{
			drawHero(wonder, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\WONDER.png");
		}
		if (c == superman)
		{
			drawHero(superman, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\SUPERMAN.png");
		}
		if (c == batman)
		{
			drawHero(batman, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\BATMAN.png");
		}
	}
	else
	{
		if (c == captain)
		{
			drawHero(captain, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\CAPTAINnp.png");
		}
		if (c == hulk)
		{
			drawHero(hulk, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\HULKnp.png");
		}
		if (c == flash)
		{
			drawHero(flash, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\FLASHnp.png");
		}
		if (c == thor)
		{
			drawHero(thor, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\THORnp.png");
		}
		if (c == wolvie)
		{
			drawHero(wolvie, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\WOLVIEnp.png");
		}
		if (c == spidey)
		{
			drawHero(spidey, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\SPIDEYnp.png");
		}
		if (c == ironman)
		{
			drawHero(ironman, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\IRONMANnp.png");
		}
		if (c == wonder)
		{
			drawHero(wonder, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\WONDERnp.png");
		}
		if (c == superman)
		{
			drawHero(superman, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\SUPERMANnp.png");
		}
		if (c == batman)
		{
			drawHero(batman, (CANVAS_WIDTH * x / numberofcards) - 2.8f, (CANVAS_HEIGHT * i / j) - 3.0f, ".\\assets\\BATMANnp.png");
		}
	}

}

void Battle::setPowers()
{
	captain->setPower(5500);
	hulk->setPower(7000);
	thor->setPower(7500);
	flash->setPower(8000);
	spidey->setPower(5200);
	ironman->setPower(5300);
	wonder->setPower(7450);
	superman->setPower(9999);
	batman ->setPower(4500);
	wolvie->setPower(6000);
}

//INFO

void Battle::drawinfobutton()
{
	Brush br;
	br.texture = std::string(ASSET_PATH) + "info4.png";
	br.outline_opacity = 0.0f;
	drawRect(CANVAS_WIDTH / 1.07, CANVAS_HEIGHT / 19, CANVAS_WIDTH / 25, CANVAS_HEIGHT / 15, br);
}

void Battle::updateinfobutton()
{
	MouseState ms;
	getMouseState(ms);

	float mx = windowToCanvasX(ms.cur_pos_x);
	float my = windowToCanvasY(ms.cur_pos_y);

	if (((distance(mx, my, CANVAS_WIDTH / 1.07, CANVAS_HEIGHT / 19)) < INFO_SIZE * 0.4f) and ms.button_left_pressed)
	{
		status = STATUS_INFO;
	}

}

void Battle::drawInfo()
{
	Brush br;
	SETCOLOR(br.fill_color, 0.5, 0.5, 0.5);
	br.outline_opacity = 0.0f;
	br.fill_opacity = 0.8f;
	drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	char info[1000];
	SETCOLOR(br.fill_color, 0.0, 0.0, 1.0);
	sprintf_s(info, "There  are  10  superhero  cards  with  power  points.");
	drawText(CANVAS_WIDTH / 9.0, CANVAS_HEIGHT / 3.0, 0.6, info, br);
	sprintf_s(info, "Every  player  gets  randomly  5  cards.");
	drawText(CANVAS_WIDTH / 5.0, CANVAS_HEIGHT / 2.4, 0.6, info, br);
	sprintf_s(info, " The  opponent  picks  a  card  and  plays  first.");
	drawText(CANVAS_WIDTH / 6.5, CANVAS_HEIGHT / 2.0, 0.6, info, br);
	sprintf_s(info, "You  should  pick  a  card  with  more  points  to  win  the  round.");
	drawText(CANVAS_WIDTH / 15.0, CANVAS_HEIGHT / 1.7, 0.6, info, br);
	sprintf_s(info, "The  defeated  card  deletes. ");
	drawText(CANVAS_WIDTH / 4.0, CANVAS_HEIGHT / 1.5, 0.6, info, br);
	sprintf_s(info, "The  player  who  has  no  cards  left  loses  and  his  opponent  wins.");
	drawText(CANVAS_WIDTH / 70.0, CANVAS_HEIGHT / 1.35, 0.58, info, br);
}

void Battle::updateInfoScreen()
{
	if (getKeyState(SCANCODE_BACKSPACE))
	{
		status = STATUS_START;
	}
}

void Battle::drawExitInfo()
{
	Brush br;
	char info[40];
	SETCOLOR(br.fill_color, 0.7, 0.0, 0.0);
	sprintf_s(info, "PRESS BACKSPACE TO EXIT INFO");
	drawText(CANVAS_WIDTH / 1.7, CANVAS_HEIGHT / 10, 0.5, info, br);
}


//START SCREEN

void Battle::updateStartScreen()
{
	m_cards = { captain, hulk, thor, flash,wolvie, spidey, ironman, wonder, superman, batman };

	if (getKeyState(SCANCODE_RETURN))
	{
		status = STATUS_PLAYING;
	}
}

void Battle::drawStartScreen()
{
	drawinfobutton();
	drawAllCards();
	drawStartingText();
}

void Battle::drawAllCards()
{
	drawHero(captain, (CANVAS_WIDTH * 1 / 5.0f) - 2.8f, (CANVAS_HEIGHT * 1 / 2.0f) - 4.0f, ".\\assets\\CAPTAINnp.png");
	drawHero(hulk, (CANVAS_WIDTH * 2 / 5.0f) - 2.8f, (CANVAS_HEIGHT * 2 / 2.0f) - 4.0f, ".\\assets\\HULKnp.png");
	drawHero(thor, (CANVAS_WIDTH * 3 / 5.0f) - 2.8f, (CANVAS_HEIGHT * 1 / 2.0f) - 4.0f, ".\\assets\\THORnp.png");
	drawHero(wolvie, (CANVAS_WIDTH * 1 / 5.0f) - 2.8f, (CANVAS_HEIGHT * 2 / 2.0f) - 4.0f, ".\\assets\\WOLVIEnp.png");
	drawHero(spidey, (CANVAS_WIDTH * 2 / 5.0f) - 2.8f, (CANVAS_HEIGHT * 1 / 2.0f) - 4.0f, ".\\assets\\SPIDEYnp.png");
	drawHero(ironman, (CANVAS_WIDTH * 5 / 5.0f) - 2.8f, (CANVAS_HEIGHT * 1 / 2.0f) - 4.0f, ".\\assets\\IRONMANnp.png");
	drawHero(wonder, (CANVAS_WIDTH * 3 / 5.0f) - 2.8f, (CANVAS_HEIGHT * 2 / 2.0f) - 4.0f, ".\\assets\\WONDERnp.png");
	drawHero(superman,( CANVAS_WIDTH * 4 / 5.0f) - 2.8f, (CANVAS_HEIGHT * 2 / 2.0f) - 4.0f, ".\\assets\\SUPERMANnp.png");
	drawHero(batman, (CANVAS_WIDTH * 5 / 5.0f) - 2.8f, (CANVAS_HEIGHT * 2 / 2.0f) - 4.0f, ".\\assets\\BATMANnp.png");
	drawHero(flash, (CANVAS_WIDTH * 4 / 5.0f) - 2.8f, (CANVAS_HEIGHT * 1 / 2.0f) - 4.0f, ".\\assets\\FLASHnp.png");
}

void Battle::drawStartingText()
{
	Brush br;
	char info[40];
	sprintf_s(info, "PRESS ENTER TO PLAY");
	drawText(CANVAS_WIDTH/20, CANVAS_HEIGHT/1.85,1.8, info, br);
}




//PLAYING SCREEN

void Battle::updatePlayingScreen()
{
	if (m_cards.size() == 10)
	{
		srand(time(0));
		cpuCards = {};
		int size_of_m_cards = 10;
		for (int i = 0; i < 5; i++) 
		{
			int random = rand() % size_of_m_cards;
			auto randomcard = m_cards.cbegin(); 	
			std::advance(randomcard, random);        
			cpuCards.push_front(*randomcard);
			m_cards.remove(*randomcard);	
			size_of_m_cards--;
		}
	}
	numberOfCpuCards = cpuCards.size();
	if (getKeyState(SCANCODE_BACKSPACE))
	{
		status = STATUS_CPU_PLAYING;
	}
}

void Battle::drawPlayingScreen()
{
	drawbackground();
	drawBattleScreen();
}

void Battle::drawBattleScreen() 
{	
	drawPlayerCards();
	drawCpuCards();
	drawPlayingText();
}

void Battle::drawPlayingText()
{
	Brush br;
	char info[40];
	sprintf_s(info, "PRESS BACKSPACE TO MAKE OPPONENT PLAY");
	drawText(CANVAS_WIDTH / 20, CANVAS_HEIGHT / 1.85, 0.9, info, br);
}

void Battle::drawPlayerCards()
{
	int x = 1;
	int i = 3;
	float j = 3.0f;
	for (Card* c : m_cards)
	{
		drawCards(false, c, x, i, j, 5.0f);
		i++;
		x++;
		j++;
	}
}

void Battle::drawCpuCards()
{
	for (int k = 0; k < cpuCards.size(); k++)
	{
		drawHero(cardflip, (CANVAS_WIDTH * (k + 1) / 5.0f) - 2.8f, CANVAS_HEIGHT * 1 / 5.5f, ".\\assets\\cardflip.png");

	}
}



//CpuPlayingScreen


void Battle::drawCpuPlayingScreen()
{
	drawPlayerCards();
	drawCpuPlayingCards();
}

void Battle::updateCpuPlayingScreen()
{
	if (cardsSelected == 0)
	{
		int random = rand() % cpuCards.size();
		auto randomcard = cpuCards.cbegin();
		std::advance(randomcard, random);        
		CpuCardSelected = *randomcard;
		cardsSelected++;
	}

	MouseState ms;
	getMouseState(ms);

	float mx = windowToCanvasX(ms.cur_pos_x);
	float my = windowToCanvasY(ms.cur_pos_y);

	for (auto c : m_cards)
	{
		if (c->contains(mx, my) and ms.button_left_pressed)
		{
			status = STATUS_PICKING_CARD;
			PlayerCardSelected = c;
		}
	}

}

void Battle::drawCpuPlayingCards()
{
	for (int k = 0; k < numberOfCpuCards - 1; k++)
	{	
		drawHero(cardflip, (CANVAS_WIDTH * (k + 1) / 5.0f) - 2.8f, CANVAS_HEIGHT * 1 / 5.5f, ".\\assets\\cardflip.png");	
	}

	drawCards(true, CpuCardSelected, 1, 2.05, 3.0f, 1.3f);

}



//PickingCardScreen

void Battle::drawPickingScreen()
{
	drawCpuPlayingCards();
	drawRestOfPlayerCards();
	drawCards(true, PlayerCardSelected, 1, 2.05, 3.0f, 2.5f);
	drawTextForWinner();
}

void Battle::updatePickingCard()
{
	if (PlayerCardSelected->getPower() > CpuCardSelected->getPower())
	{
		cpuCards.remove(CpuCardSelected);
	}
	if (PlayerCardSelected->getPower() < CpuCardSelected->getPower())
	{
		m_cards.remove(PlayerCardSelected);
	}

	cardsSelected = 0;

	if (getKeyState(SCANCODE_RETURN))
	{
		status = STATUS_PLAYING;
	}

	if (m_cards.size() == 0 or cpuCards.size() == 0)
	{
		status = STATUS_ENDGAME;
	}
}

void Battle::drawRestOfPlayerCards()
{
	cards_remain = m_cards;
	cards_remain.remove(PlayerCardSelected);

	float numberofcards = cards_remain.size();
	float i = 3;
	float j = 3.0f;
	int x = 1;

	for (auto c : cards_remain)
	{	
		drawCards(false, c, x, i, j, numberofcards);
		i++;
		j++;
		x++;
	}

}

void Battle::drawTextForWinner()
{
	Brush br;
	SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
	char info[40];
	if (PlayerCardSelected->getPower() > CpuCardSelected->getPower())
	{
		sprintf_s(info, "YOU WON! OPONENTS CARD IS YOURS!");		
		drawText(CANVAS_WIDTH / 9, CANVAS_HEIGHT / 4.0, 1.0, info, br);
	}
	if (PlayerCardSelected->getPower() < CpuCardSelected->getPower())
	{
		sprintf_s(info, "OPONENT WINS... HE GETS YOUR CARD!");
		drawText(CANVAS_WIDTH / 9, CANVAS_HEIGHT / 4.0, 1.0, info, br);
	}
	SETCOLOR(br.fill_color, 0.0f, 0.0f, 1.0f);
	sprintf_s(info, "PRESS ENTER TO CONTINUE");
	drawText(CANVAS_WIDTH / 20, CANVAS_HEIGHT / 1.0, 1.5, info, br);
}


//ENDGAME


void Battle::QuitGame()
{
	if (getKeyState(SCANCODE_ESCAPE))
	{
		stopMessageLoop();
	}	
}

void Battle::drawGameOver()
{
	Brush br;
	SETCOLOR(br.fill_color, 0.0f, 0.0f, 1.0f);
	char info[40];

	if (m_cards.size() > cpuCards.size())
	{
		sprintf_s(info, "GAME OVER! YOU WON!");
		drawText(CANVAS_WIDTH / 6.5, CANVAS_HEIGHT / 2.0, 1.5, info, br);
	}

	if (m_cards.size() < cpuCards.size())
	{
		sprintf_s(info, "GAME OVER! OPPONENT WINS...");
		drawText(CANVAS_WIDTH / 50, CANVAS_HEIGHT / 2.0, 1.5, info, br);
	}

	SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
	sprintf_s(info, "PRESS ESC TO QUIT GAME..");
	drawText(CANVAS_WIDTH / 12.0, CANVAS_HEIGHT / 1.2, 0.7, info, br);
}





Battle::Battle()
{
}



Battle::~Battle()
{
}

Battle* Battle::getInstance()
{
	if (!m_instance)
	{
		m_instance = new Battle();
	}
		
	return m_instance;
}

void Battle::releaseInstance()
{
	if (m_instance)
	{
		delete m_instance;
	}

	m_instance = nullptr;

}

Battle* Battle::m_instance = nullptr;
