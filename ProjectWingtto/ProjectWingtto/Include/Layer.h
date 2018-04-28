//Scene내에서 Object들을 관리하기 위한 클래스.


#include "../pch.h"



class Layer
{
public:
	Layer();
	Layer(const std::string tag, unsigned int order = 0);
	~Layer();


public:
	bool Init();
	void Update(float deltaTime);
	void Render(float deltaTime, const HDC& hdc);


public:
	std::string GetLayerTag() const { return m_strTag; }
	unsigned int GetLayerOrder() const { return m_iLayerOrder; }
	void SetLayerTag(std::string layerTag) { m_strTag = layerTag; }
	void SetLayerOder(unsigned int order) { m_iLayerOrder = order; }
	//inline bool CompareOrder(const Layer& layer1, const Layer& layer2) { return (layer1.m_iLayerOrder > layer2.m_iLayerOrder); }


public:
	void AddObject(class Object* obj);
	

private:
	std::string								m_strTag;
	unsigned int							m_iLayerOrder;
	std::list<class Object*>				m_lObjectList;
	std::list<class Object*>::iterator	m_lIt;


};
