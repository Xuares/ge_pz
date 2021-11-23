// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReloadableInterface.h"
#include "GameFramework/Actor.h"
#include "Engine/SkeletalMeshSocket.h"
#include "BaseWeapon.generated.h"

UCLASS()
class GE_PZ_API ABaseWeapon : public AActor, public IReloadableInterface
{
	GENERATED_BODY()
	
public:	
	ABaseWeapon();

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	USkeletalMeshComponent* MeshComponent;
	
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Begin IReloadableInterface override
	UFUNCTION(BlueprintCallable)
	virtual void Reload() override;
	UFUNCTION(BlueprintCallable)
	virtual bool CanReload() override;
	// End IReloadableInterface override

	
	UFUNCTION(BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintCallable)
	bool CanFire() const;

	UFUNCTION(BlueprintCallable)
	void UseAmmo();

	UFUNCTION(BlueprintCallable)
	void RefillClip();
	
	UFUNCTION(BlueprintCallable)
	void WeaponTrace();
	
	// максимальное кол-во патронов
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int32 MaxAmmo;

	// кол-во патронов в магазине
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 AmmoPerClip;

	// кол-во урона которое наносит оружие
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 Damage;

	// время перезарядки
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	float ReloadDuration;

	// текущее количество патронов у персонажа
	UPROPERTY(BlueprintReadWrite)
	int32 CurrentAmmo;

	// текущее количество патронов в магазине
	UPROPERTY(BlueprintReadWrite)
	int32 CurrentAmmoInClip;

	// перезагружается ли в данный момент
	UPROPERTY(BlueprintReadOnly)
	bool bIsReloading;

	// дальность выстрела (трейса)
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 Range;

	// имя сокета, назначенное в меше
	UPROPERTY(BlueprintReadWrite)
	FName MuzzleSocketName;
};
