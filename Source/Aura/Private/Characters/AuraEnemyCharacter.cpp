﻿// Copyright VisionLooks


#include "Characters/AuraEnemyCharacter.h"


// Sets default values
AAuraEnemyCharacter::AAuraEnemyCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAuraEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();
    
}

// Called every frame
void AAuraEnemyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAuraEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

}

