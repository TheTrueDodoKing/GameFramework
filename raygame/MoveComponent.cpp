#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"

MoveComponent::MoveComponent(float maxSpeed, Actor* owner) : Component(owner, "MoveComponent")
{
	m_maxSpeed = maxSpeed;
}

void MoveComponent::update(float deltaTime)
{
	//Store what the current position is.
	MathLibrary::Vector2 posistion = getOwner()->getTransform()->getLocalPosition();

	//If the velocity is over the maximum speed...
	if (getVelocity().getMagnitude() > getMaxSpeed())
	{
		MathLibrary::Vector2 newVelocity = getVelocity().getNormalized() * getMaxSpeed();
		setVelocity(newVelocity);
	}

	//posisition = position by the velocity to get the new position.
	posistion = posistion + getVelocity() * deltaTime;
	//Set the tranform's position to be the new position.
	getOwner()->getTransform()->setLocalPosition(posistion);
}