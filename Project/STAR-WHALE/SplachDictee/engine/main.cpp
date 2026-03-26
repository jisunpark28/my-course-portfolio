#include "SplashEngine.h"

int main() {

    SplashEngine engine("Jisun", 101);

    engine.loadMissions();

    engine.play();

    engine.saveProgress();

    return 0;
}