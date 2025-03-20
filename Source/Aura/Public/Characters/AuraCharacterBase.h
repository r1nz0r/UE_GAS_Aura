// Copyright VisionLooks

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter
{
    GENERATED_BODY()

public:
    AAuraCharacterBase();

protected:

    UPROPERTY(EditAnywhere, Category = "Combat")
    TObjectPtr<USkeletalMeshComponent> Weapon;

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    FName WeaponSocketName = "WeaponHandSocket";
    
    virtual void BeginPlay() override;
};
