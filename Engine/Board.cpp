#include "Board.h"
#include "Colors.h"
void Board::draw(Graphics& gfx)
{
	gfx.DrawRect(getRect(), SpriteCodex::baseColor);
	for (Vei2 vect = { 0,0 }; vect.y < height; vect.y++) {
		for (vect.x = 0; vect.x < width; vect.x++) {
			tileAt(vect).draw(gfx, gridToScreen(vect));
		}
	}
}

Board::Tile Board::tileAt(Vei2& gridPos)
{
	return tiles[width * gridPos.y + gridPos.x];
}

RectI Board::getRect()
{
	return RectI(Vei2(0, 0), SpriteCodex::tileSize * width, SpriteCodex::tileSize * height);
}

void Board::Tile::draw(Graphics& gfx, Vei2& screenPos)
{
	SpriteCodex::DrawTileButton(screenPos, gfx);
}

Vei2 Board::gridToScreen(Vei2& gridPos)
{
	return gridPos * SpriteCodex::tileSize;
}

Vei2 Board::screenToGrid(Vei2& screenPos)
{
	return screenPos / SpriteCodex::tileSize;
}

