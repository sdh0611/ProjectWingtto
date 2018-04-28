#include "../pch.h"
#include "./ComponentBase.h"


class InputComponent : public ComponentBase
{
public:
	InputComponent();
	~InputComponent();


public:
	virtual bool Init(class Object* object) override;
	virtual void Update(const float& deltaTime) override;


private:
	class MoveObject*	m_pOwner;


};
