//
// Created by zouz on 28/01/18.
//

#ifndef LIFEISBORNE_SCENES_HPP
#define LIFEISBORNE_SCENES_HPP

#include "../../Lib/better-enums/enum.h"

namespace Scenes
{

    BETTER_ENUM(SceneType,
                int,
                SalleArcade = 0,
                Vestiaire,
                Regie,
                Shop,
                Game,
                Lobby,
                Intro,
                TestScene
    )
}

#endif //LIFEISBORNE_SCENES_HPP
