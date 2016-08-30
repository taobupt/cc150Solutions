#include"Header.h"
#include"struct.h"
enum Color{
	BLACK, WHITE, GREEN, BULE, ORANGE
};
void paintFill(Color** screen, int m, int n, int x, int y, Color oldColor, Color newColor)
{
	if (x < 0 || x >= m || y < 0 || y >= n)return;
	if (screen[x][y] == oldColor)
	{
		screen[x][y] = newColor;
		paintFill(screen, m, n, x - 1, y, oldColor, newColor);
		paintFill(screen, m, n, x, y - 1, oldColor, newColor);
		paintFill(screen, m, n, x + 1, y, oldColor, newColor);
		paintFill(screen, m, n, x, y + 1, oldColor, newColor);
	}
	return;
}