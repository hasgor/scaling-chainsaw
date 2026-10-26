#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/CCScheduler.hpp>

using namespace geode::prelude;

class $modify(NoclipPlayLayer, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        if (Mod::get()->getSettingValue<bool>("noclip") && object != m_anticheatSpike) return;
        PlayLayer::destroyPlayer(player, object);
    }
};

class $modify(SpeedScheduler, CCScheduler) {
    void update(float dt) {
        float s = static_cast<float>(Mod::get()->getSettingValue<double>("speed"));
        CCScheduler::update(dt * s);
    }
};
