#include "BaseTower.h"
#include "GameManager.h"


BaseTower::BaseTower() {
}


BaseTower::~BaseTower() {
}

bool BaseTower::init() {
	if (!Sprite::init()) {
		return false;
	}
	return true;
}

void BaseTower::checkNearestMonster() {
	// ȫ��Vector�����������洢��ǰ�ؿ��ĵ���  
	auto monsters = GameManager::getInstance()->Monsters();

	nearest_monster_ = nullptr;
	for (int i = 0; i < monsters.size(); i++) {
		auto monster = monsters.at(i);
		double distance = this->getParent()->getPosition().getDistance(monster->getPosition());

		// �������ķ�Χ�ڣ��ҹ�����Ա�������ĳЩ���¹���ֻ�����������Ա�������
		if (distance < this->scope_) {   
			this->scope_ = distance;// ������С���룬�ҵ�����Ĺ���  
			nearest_monster_ = monster;
		}
	}
}
