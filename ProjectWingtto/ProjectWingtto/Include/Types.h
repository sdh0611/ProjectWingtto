#pragma once


#include "../pch.h"


namespace Types {

	typedef struct _tagRectangle{
		float top;
		float bottom;
		float right;
		float left;
	}RECTANGLE;
		
	typedef struct _tagPoint {
		float x;
		float y;

		_tagPoint() : x(0), y(0) {		 }

		_tagPoint(float _x, float _y) : x(_x), y(-y) {	}

		_tagPoint(const _tagPoint& other) : x(other.x), y(other.y) {	}

		void operator=(const _tagPoint& other) {
			x = other.x;
			y = other.y;
		}

		_tagPoint operator +(const _tagPoint& other) {
			return _tagPoint(this->x + other.x, this->y + other.y);
		}
		 
		_tagPoint operator *(const _tagPoint& other) {
			return _tagPoint(this->x * other.x, this->y * other.y);
		}

	

	}POINT;

	typedef struct _tagSize {
		unsigned int width;
		unsigned int height;
	}SIZE;
	

	enum SceneType{ ST_EMPTY, ST_TITLE, ST_GAME, ST_SELECT };
	
	enum ObjectType{ OT_PLAYER, OT_ENUMY, OT_PROB, OT_PICKUP };

	enum Direction{ DIR_DOWN = -1, DIR_IDLE, DIR_UP, DIR_LEFT, DIR_RIGHT};

	enum ObjectState{ OS_IDLE, OS_MOVE, OS_ACCEL, OS_JUMP, OS_STOP, OS_ATTACK, OS_DAMAGED };

	enum ColliderType{ CT_RECT, CT_CIRCLE, CT_PIXEL };

}