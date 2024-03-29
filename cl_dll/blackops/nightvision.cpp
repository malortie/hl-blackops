/***
*
*	Copyright (c) 1996-2002, Valve LLC. All rights reserved.
*
*	This product contains software technology licensed from Id
*	Software, Inc. ("Id Technology").  Id Technology (c) 1996 Id Software, Inc.
*	All Rights Reserved.
*
*   Use, distribution, and modification of this source code and/or resulting
*   object code is restricted to non-commercial enhancements to products from
*   Valve LLC.  All other use, distribution, or modification is prohibited
*   without written permission from Valve LLC.
*
****/

#include "hud.h"
#include "cl_util.h"
#include "parsemsg.h"

#include <string.h>
#include <stdio.h>

DECLARE_MESSAGE(m_Nightvision, Nightvision)

int CHudNightvision::Init(void)
{
	m_iFlags = 0;

	HOOK_MESSAGE(Nightvision);

	gHUD.AddHudElem(this);

	return 1;
};

void CHudNightvision::Reset(void)
{
	m_iFlags &= ~HUD_ACTIVE;
}

int CHudNightvision::VidInit(void)
{
	return 1;
};

int CHudNightvision::MsgFunc_Nightvision(const char *pszName, int iSize, void *pbuf)
{
	BEGIN_READ(pbuf, iSize);
	int fActive = READ_BYTE();

	if (fActive)
		m_iFlags |= HUD_ACTIVE;
	else
		m_iFlags &= ~HUD_ACTIVE;

	return 1;
}


int CHudNightvision::Draw(float flTime)
{
	if (!(m_iFlags & HUD_ACTIVE))
		return 0;

	if (!(gHUD.m_iWeaponBits & (1 << (WEAPON_SUIT))))
		return 1;

	int r, g, b, a;
	int x, y, w, h;

	r = 128;
	g = b = 0;
	a = 64;

	x = y = 0;
	w = ScreenWidth;
	h = ScreenHeight;

	FillRGBA( x, y, w, h, r, g, b, a );

	return 1;
}
