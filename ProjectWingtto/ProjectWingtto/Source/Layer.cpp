#include "..\Include\Layer.h"
#include "../Include/Object.h"


Layer::Layer() :
	m_strTag(""), m_iLayerOrder(0)
{

}

Layer::Layer(const std::string tag, unsigned int order) :
	m_strTag(tag), m_iLayerOrder(order)
{
	
}


Layer::~Layer()
{

	for (m_lIt = m_lObjectList.begin(); m_lIt != m_lObjectList.end(); ++m_lIt) {
		delete *m_lIt;
	}

	m_lObjectList.clear();

}

bool Layer::Init()
{
	for (m_lIt = m_lObjectList.begin(); m_lIt != m_lObjectList.end(); ++m_lIt) {
		if (!(*m_lIt)->Init())
			return false;
	}
		
	return true;
}

void Layer::Update(float deltaTime)
{

	for (m_lIt = m_lObjectList.begin(); m_lIt != m_lObjectList.end(); ++m_lIt) {
		(*m_lIt)->Update(deltaTime);
	}

}

void Layer::Render(float deltaTime, const HDC& hDC)
{
	for (m_lIt = m_lObjectList.begin(); m_lIt != m_lObjectList.end(); ++m_lIt) {
		(*m_lIt)->Render(deltaTime, hDC);
	}

}

void Layer::AddObject(Object * obj)
{

	m_lObjectList.push_back(obj);

}
