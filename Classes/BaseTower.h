#ifndef BASETOWER_H
#define BASETOWER_H

#include "cocos2d.h"
#include "Monster.h"

USING_NS_CC;

class BaseTower: public Sprite {
public:
	BaseTower();
	~BaseTower();

	bool init() override;

private:
	enum TowerType {
		ARCHER, MILITIA, MAGE, BOMBARD
	};

	// ����
	CC_SYNTHESIZE(TowerType, type_, Type);

	// �����
	// CC_SYNTHESIZE(Terrain*, myTerrain, MyTerrain);

	// ����
	CC_SYNTHESIZE(std::string, tower_name_, TowerName);
	// �ȼ�
	CC_SYNTHESIZE(int, level_, Level);
	// ��Χ
	CC_SYNTHESIZE(float, scope_, Scope);
	// ������Χ
	CC_SYNTHESIZE(float, next_scope_, NextScope);
	// �����ٶ�
	CC_SYNTHESIZE(float, rate_, Rate);
	// ������
	CC_SYNTHESIZE(int, power_, Power);
	// ���������Ǯ
	CC_SYNTHESIZE(int, upgrade_price_, UpgradePrice);
	// �۳�ʱ������Ǯ
	CC_SYNTHESIZE(int, selling_price, SellingPrice);

public:
	virtual void upgradeTower() = 0;//����������������������  
	virtual void sellTower() = 0;//����������  
	virtual void removeTower() = 0;//�Ƴ�������  
	virtual void showTowerInfo() = 0;//��ʾ��������Ϣ  
	virtual void upgradeOne() = 0;//������������  
	virtual void upgradeTwo() = 0;
	virtual void setRallyPoint(Vec2 pos) = 0;//��Ӫ�������ü����

protected:
	virtual void checkNearestMonster();//��⸽������  
	//virtual void showUpgradeMenu();//��ʾ����ѡ��
	//virtual void hideUpgradeMenu();//����
	//void setListener();//����ĳЩ�����¼�

	Sprite* terrain;//�����Ľ����  
	Monster* nearestMonster;  //�����ĵ���  
};

#endif
