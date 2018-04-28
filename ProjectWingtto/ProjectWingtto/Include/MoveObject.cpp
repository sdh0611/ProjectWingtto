#include "../pch.h"
#include "../Include/Object.h"
#include "MoveObject.h"

MoveObject::MoveObject(Types::ObjectType type, Types::POINT point, Types::SIZE size):
	Object(type, point, size), 
	m_Direction(Types::DIR_IDLE), m_pPhysics(nullptr)
{


}

MoveObject::~MoveObject()
{

	SAFE_DELETE(m_pPhysics)

}
