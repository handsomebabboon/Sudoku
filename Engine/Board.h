#pragma once
#include"Graphics.h"
#include "Vei2.h"
#include "SpriteCodex.h"
#include "RectI.h"
class Board
{
private:
	class Tile {
	private:
		
	public:
		void draw(Graphics& gfx,Vei2& screenPos);
		
	};

public:
	Vei2 gridToScreen(Vei2& gridPos);
	Vei2 screenToGrid(Vei2& screenPos);
	void draw(Graphics& gfx);
	Tile tileAt(Vei2& gridPos);
	RectI getRect();
private:
	int static constexpr height = 9;
	int static constexpr width = 9;
	Tile tiles[width * height];
};

