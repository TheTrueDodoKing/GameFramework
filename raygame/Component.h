#pragma once
class Actor;

class Component
{
public:
	
	Component();
	Component(Actor* owner, const char* name);

	virtual ~Component();

	/// <summary>
	/// Called before the first update.
	/// </summary>
	virtual void start() {};

	/// <summary>
	/// Called evertyime the game loops.
	/// </summary>
	/// <param name="deltatime">The amount of time that has passed between this frame the the previous frame.</param>
	virtual void update(float deltatime) {};

	/// <summary>
	/// Called after update in order to updates visuals.
	/// </summary>
	virtual void draw() {};

	/// <summary>
	/// Caled when the scene ends or
	/// when an actor is removed form the scene.
	/// </summary>
	virtual void end() {};

	/// <summary>
	/// Called when the attached actor overlaps with another.
	/// </summary>
	/// <param name="other">The actor the owner overlapped.</param>
	virtual void onCollision(Actor* other) {};

	/// <summary>
	/// Called rightr before the actor is going to be destroyed.
	/// </summary>
	virtual void onDestroy() {};

	/// <returns>Gets the name of this componenet.
	/// Is usually the typ name.</returns>
	const char* getName() { return m_name; }

	/// <returns>Gets the actor is component is attached to.</returns>
	Actor* getOwner() { return m_owner; }

private:
	const char* m_name;
	Actor* m_owner;
};

