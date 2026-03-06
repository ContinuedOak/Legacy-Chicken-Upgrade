#include "stdafx.h"
#include "..\Minecraft.World\Mth.h"
#include "ChickenModel.h"
#include "ModelPart.h"

ChickenModel::ChickenModel() : Model()
{
	// Model by ContinuedOak

    int yo = 16;
	
	// --- Head ---
    head = new ModelPart(this, 0, 0);
    head->addBox(-2.0f, -6.0f, -2.0f, 4, 6, 3, 0.0f); // Head
    head->setPos(0, (float)(-1 + yo), -4);

	// Cold Chicken Variant Hair
	hair = new ModelPart(this, 44, 0);
	hair->addBox(-3.0f, -6.2f, -2.2f, 6, 3, 4, 0.0f);
	hair->setPos(0, (float)(-1 + yo), -4);

	// Fancy Head Feather
	fancyHair = new ModelPart(this, 20, 16);
	fancyHair->addBox(-0.0f, -13.0f, -3.0f, 0, 8, 8, 0.0f);
	fancyHair->setPos(0, (float)(-1 + yo), -4);

	// --- Beak ---
    beak = new ModelPart(this, 14, 0);
    beak->addBox(-2.0f, -4.0f, -4.0f, 4, 2, 2, 0.0f);
    beak->setPos(0, (float)(-1 + yo), -4);

	// --- redThing ---
    redThing = new ModelPart(this, 14, 4);
    redThing->addBox(-1.0f, -2.0f, -3.0f, 2, 2, 2, 0.0f);
    redThing->setPos(0, (float)(-1 + yo), -4);

	// --- Body ---
    body = new ModelPart(this, 0, 9);
    body->addBox(-3.0f, -4.0f, -3.0f, 6, 8, 6, 0.0f); // Body
    body->setPos(0, (float)(0 + yo), 0);

	// Fancy Tail Feather
	tailFather = new ModelPart(this, 41, 15);
    tailFather->addBox(0.0f, -10.0f, 3.0f, 0, 10, 7, 0.0f);
    tailFather->setPos(0, (float)(0 + yo), 0);
	
	// --- Left Leg ---
    leg0 = new ModelPart(this, 26, 0);
    leg0->addBox(-1.0f, 0.0f, -3.0f, 3, 5, 3);
    leg0->setPos(-2, (float)(3 + yo), 1);

	// --- Leg Right ---
    leg1 = new ModelPart(this, 26, 0);
    leg1->addBox(-1.0f, 0.0f, -3.0f, 3, 5, 3);
    leg1->setPos(1, (float)(3 + yo), 1);

	// --- Wing Left ---
    wing0 = new ModelPart(this, 24, 13);
    wing0->addBox(0.0f, 0.0f, -3.0f, 1, 4, 6);
    wing0->setPos(-4, (float)(-3 + yo), 0);

	// --- Wing Right ---
    wing1 = new ModelPart(this, 24, 13);
    wing1->addBox(-1.0f, 0.0f, -3.0f, 1, 4, 6);
    wing1->setPos(4, (float)(-3 + yo), 0);

	// 4J added - compile now to avoid random performance hit first time cubes are rendered
    head->compile(1.0f/16.0f);
    beak->compile(1.0f/16.0f);
	hair->compile(1.0f/16.0f);
	fancyHair->compile(1.0f/16.0f);
    redThing->compile(1.0f/16.0f);
    body->compile(1.0f/16.0f);
	tailFather->compile(1.0f/16.0f);
    leg0->compile(1.0f/16.0f);
    leg1->compile(1.0f/16.0f);
    wing0->compile(1.0f/16.0f);
    wing1->compile(1.0f/16.0f);
}

void ChickenModel::render(shared_ptr<Entity> entity, float time, float r, float bob, float yRot, float xRot, float scale, bool usecompiled)
{
    setupAnim(time, r, bob, yRot, xRot, scale);
	if (young) 
	{
		float ss = 2;
		glPushMatrix();
		glTranslatef(0, 5 * scale, 2 * scale);
		head->render(scale,usecompiled);
		hair->render(scale,usecompiled);
		fancyHair->render(scale,usecompiled);
		beak->render(scale,usecompiled);
		redThing->render(scale,usecompiled);
		glPopMatrix();
		glPushMatrix();
		glScalef(1 / ss, 1 / ss, 1 / ss);
		glTranslatef(0, 24 * scale, 0);
		body->render(scale,usecompiled);
		tailFather->render(scale,usecompiled);
		leg0->render(scale,usecompiled);
		leg1->render(scale,usecompiled);
		wing0->render(scale,usecompiled);
		wing1->render(scale,usecompiled);
		glPopMatrix();
	} 
	else 
	{
		head->render(scale,usecompiled);
		beak->render(scale,usecompiled);
		hair->render(scale,usecompiled);
		fancyHair->render(scale,usecompiled);
		redThing->render(scale,usecompiled);
		body->render(scale,usecompiled);
		tailFather->render(scale,usecompiled);
		leg0->render(scale,usecompiled);
		leg1->render(scale,usecompiled);
		wing0->render(scale,usecompiled);
		wing1->render(scale,usecompiled);
	}
}

void ChickenModel::setupAnim(float time, float r, float bob, float yRot, float xRot, float scale, unsigned int uiBitmaskOverrideAnim)
{
	head->xRot = xRot / (float) (180 / PI);
	head->yRot = yRot / (float) (180 / PI);
        
	beak->xRot = head->xRot;
	beak->yRot = head->yRot;

	hair->xRot = head->xRot;
	hair->yRot = head->yRot;

	fancyHair->xRot = head->xRot;
	fancyHair->yRot = head->yRot;
        
	redThing->xRot = head->xRot;
	redThing->yRot = head->yRot;
        
	body->xRot = 90 / (float) (180 / PI);

	leg0->xRot = (Mth::cos(time * 0.6662f) * 1.4f) * r;
	leg1->xRot = ( Mth::cos(time * 0.6662f + PI) * 1.4f) * r;
	wing0->zRot = bob;
	wing1->zRot = -bob;
}
