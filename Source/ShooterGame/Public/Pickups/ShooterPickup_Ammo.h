// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ShooterPickup.h"
#include "ShooterPickup_Ammo.generated.h"

class AShooterCharacter;
class AShooterWeapon;

// A pickup object that replenishes ammunition for a weapon
UCLASS(Abstract, Blueprintable)
class AShooterPickup_Ammo : public AShooterPickup
{
	GENERATED_UCLASS_BODY()

	/** check if pawn can use this pickup */
	UFUNCTION(BlueprintPure)
	virtual bool CanBePickedUp(AShooterCharacter* TestPawn) const override;

	UFUNCTION(BlueprintPure)
	bool IsForWeapon(UClass* WeaponClass);

protected:

	/** how much ammo does it give? */
	UPROPERTY(BlueprintReadWrite, Category=Pickup)
	int32 AmmoClips;

	/** which weapon gets ammo? */
	UPROPERTY(EditDefaultsOnly, Category=Pickup)
	TSubclassOf<AShooterWeapon> WeaponType;

	/** give pickup */
	virtual void GivePickupTo(AShooterCharacter* Pawn) override;
};
