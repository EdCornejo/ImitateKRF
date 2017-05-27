#include "BaseIcon.h"
#include "RingPanel.h"


BaseIcon::BaseIcon() {
}


BaseIcon::~BaseIcon() {
}

bool BaseIcon::init() {
	if (!Sprite::init()) {
		return false;
	}

	this->initWithSpriteFrameName("main_icons_0014.png");

	confirm_ = Sprite::createWithSpriteFrameName("main_icons_0019.png");
	confirm_->setAnchorPoint(Vec2(0.0f, 0.0f));
	confirm_->setVisible(false);
	this->addChild(confirm_, 3);

	auto click_listener = EventListenerTouchOneByOne::create();
	click_listener->setSwallowTouches(true);

	click_listener->onTouchBegan = [=](Touch *touch, Event *event)->bool {
		if (this->getBoundingBox().containsPoint(this->getParent()->convertTouchToNodeSpace(touch))) {
			return true;
		}
		return false;
	};

	click_listener->onTouchEnded = [=](Touch *touch, Event *event) {
		if (!selected_) {
			confirm_->setVisible(true);
		} else {
			onClicked();
			confirm_->setVisible(false);
			static_cast<RingPanel *>(this->getParent())->hide();
		}
		selected_ = !selected_;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(click_listener, this);

	return true;
}
