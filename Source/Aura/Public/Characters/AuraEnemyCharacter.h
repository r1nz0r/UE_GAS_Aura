// Copyright VisionLooks

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemyCharacter.generated.h"

UCLASS()
class AURA_API AAuraEnemyCharacter : public AAuraCharacterBase, public IEnemyInterface
{
    GENERATED_BODY()

    AAuraEnemyCharacter();
public:
    virtual void HighlightActor() override;
    virtual void UnHighlightActor() override;
};
