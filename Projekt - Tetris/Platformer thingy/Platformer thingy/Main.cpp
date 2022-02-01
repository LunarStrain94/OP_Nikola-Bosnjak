#include "Game.hpp"

int main()
{
	srand(time(NULL));
	while (true) {
		Game b(12, 22);
		Player pl;
		int c = 0;
		int t = b.mainMenu();
		if (t == 0)
			break;
		b.initPlayer(pl);

		while (true) {
			goToZero();
			if (_kbhit())
				c = _getch();
			else
				c = 0;
			b.updatePlayer(pl, c);
			b.display();
			int posY = pl.getYpos();
			if (posY == 20 && (b.checkPlayer(pl, KEY_DOWN) == false)) {
				Sleep(1000);
				break;
			}
		}
	}
}
