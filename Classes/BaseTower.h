#ifndef BASETOWER_H
#define BASETOWER_H

#include "cocos2d.h"
#include "Monster.h"

USING_NS_CC;

class BaseTower: public Sprite {

public:
	enum TowerType {
		ARCHER, MILITIA, MAGE, BOMBARD, UNDEFINED
	};

public:
	explicit BaseTower(TowerType type = UNDEFINED, 
			  std::string name = "", 
			  int level = 0,
			  float scope = 0,
			  float next_scope = 0,
			  float rate = 0,
			  float power = 0,
			  int upgrade_price = 0,
			  int selling_price = 0,
			  Monster *nearest_monster = nullptr);
	~BaseTower();

	bool init() override;


private:
	// ����
	CC_SYNTHESIZE(TowerType, type_, Type);
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
	CC_SYNTHESIZE(float, power_, Power);
	// ���������Ǯ
	CC_SYNTHESIZE(int, upgrade_price_, UpgradePrice);
	// �۳�ʱ������Ǯ
	CC_SYNTHESIZE(int, selling_price, SellingPrice);
	// ����ĵ���
	CC_SYNTHESIZE(Monster *, nearest_monster_, NearestMonster);

public:
	virtual void attack() = 0;
	virtual void upgradeTower() = 0; 
	virtual void sellTower() = 0;
	virtual void removeTower() = 0;
	virtual void showTowerInfo() = 0; 
	virtual void upgradeOne() = 0;
	virtual void upgradeTwo() = 0;
	virtual void setRallyPoint(Vec2 pos) = 0;
	virtual void buildingAnimation() = 0;
	virtual void buildingSmokeAnimation() = 0;

protected:
	virtual void checkNearestMonster();//��⸽������
	virtual void initTower(int level) = 0;
	//virtual void showUpgradeMenu();//��ʾ����ѡ��
	//virtual void hideUpgradeMenu();//����
	//void setListener();//����ĳЩ�����¼�
};

#endif
