//-----------------------------------------------------------------------------
// File: CPlayer.cpp
//
// Desc: This file stores the player object class. This class performs tasks
//	   such as player movement, some minor physics as well as rendering.
//
// Original design by Adam Hoult & Gary Simmons. Modified by Mihai Popescu.
//-----------------------------------------------------------------------------

#ifndef _CPLAYER_H_
#define _CPLAYER_H_

//-----------------------------------------------------------------------------
// CPlayer Specific Includes
//-----------------------------------------------------------------------------
#include "Main.h"
#include "Sprite.h"

//-----------------------------------------------------------------------------
// Main Class Definitions
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Name : CPlayer (Class)
// Desc : Player class handles all player manipulation, update and management.
//-----------------------------------------------------------------------------
class CPlayer
{
public:
	//-------------------------------------------------------------------------
	// Enumerators
	//-------------------------------------------------------------------------
	enum DIRECTION 
	{ 
		DIR_FORWARD	 = 1, 
		DIR_BACKWARD	= 2, 
		DIR_LEFT		= 4, 
		DIR_RIGHT	   = 8, 
	};

	enum ESpeedStates
	{
		SPEED_START,
		SPEED_STOP
	};

	//-------------------------------------------------------------------------
	// Constructors & Destructors for This Class.
	//-------------------------------------------------------------------------
			 CPlayer(const BackBuffer *pBackBuffer);
	virtual ~CPlayer();

	//-------------------------------------------------------------------------
	// Public Functions for This Class.
	//-------------------------------------------------------------------------
	void					Update( float dt );
	void					Draw();
	void					Move(ULONG ulDirection);
	Vec2&					Position();
	Vec2&					Velocity();
	Vec2& PositionBullet();
	double getWidthBullet();
	void                  GeterPositionX(double &x);
	void                  GeterPositionY(double &y);
	double                getWidth();
	bool                  ifExploded();
	bool				ifWalking();
	void                  MoveLeft(const BackBuffer* pBackBuffer);
	void                  MoveRight(const BackBuffer* pBackBuffer);
	void                  MoveUp(const BackBuffer* pBackBuffer);
	void                  MoveDown(const BackBuffer* pBackBuffer);
	
	int                   getLives();

	void					Explode();
	bool					AdvanceExplosion();
	void	Walk();
	bool AdvanceWalk();
	void                    Shoot();
	void                   checkShoot();
private:
	//-------------------------------------------------------------------------
	// Private Variables for This Class.
	//-------------------------------------------------------------------------
	Sprite*					m_pSprite;
	Sprite*                 bullet;
	Sprite*                 bullet2;
	ESpeedStates			m_eSpeedState;
	float					m_fTimer;
	
	bool					m_bExplosion;
	bool					m_bWalking;
	bool                    m_bullet;
	
	AnimatedSprite*			m_pExplosionSprite;
	AnimatedSprite* m_pWalkingSprite;

	int						m_iExplosionFrame;
	int						m_iWalkingFrame;
	
};

#endif // _CPLAYER_H_