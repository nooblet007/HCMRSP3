#ifndef SCENE_SP3_H
#define SCENE_SP3_H

#include "GameObject.h"
#include <vector>
#include "SceneBase.h"
#include <fstream>
#include <sstream>
using std::stoi;
using std::ifstream;


class SceneSP3 : public SceneBase
{
	static const int MAX_SPEED = 10;
	static const int BULLET_SPEED = 50;
	static const int MISSILE_SPEED = 20;
	static const int MISSILE_POWER = 1;

public:
	SceneSP3();
	~SceneSP3();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

	void RenderGO(GameObject *go);

	GameObject* FetchGO();
	bool CheckCollision(GameObject *go, GameObject *other, double dt);
	float CheckCollision2(GameObject *go1, GameObject *go2);
	bool CheckCollision3(GameObject *go, GameObject *other, double dt);
	void CollisionResponse(GameObject *go, GameObject *other);

	void Reset();
protected:

	//Physics
	std::vector<GameObject *> m_goList;
	float m_speed;
	float m_worldWidth;
	float m_worldHeight;
	float m_estimatedTime;
	GameObject *m_ghost;
	int m_objectCount;

	//Auditing
	float m1, m2;
	Vector3 u1, u2, v1, v2;
};

#endif