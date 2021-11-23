// Fill out your copyright notice in the Description page of Project Settings.


#include "./BaseWeapon.h"

#include "DrawDebugHelpers.h"

// Sets default values
ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("Body");
	MeshComponent->SetupAttachment(RootComponent);

	MuzzleSocketName = "Muzzle";
	
	MaxAmmo = 60;
	AmmoPerClip = 8;
	Damage = 6;
	ReloadDuration = 2.0;
	Range = 1000;
	CurrentAmmo = 60;
	CurrentAmmoInClip = 8;
	bIsReloading = false;
}

void ABaseWeapon::Reload()
{
	if (!CanReload() || bIsReloading)
	{
		return;
	}

	bIsReloading = true;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Reloading"));

	FTimerHandle UnusedHandle;
	FTimerDelegate TimerCallback;
	TimerCallback.BindLambda([&]
	{
		RefillClip();
		bIsReloading = false;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Reloaded"));
	});

	GetWorldTimerManager().SetTimer(UnusedHandle, TimerCallback, ReloadDuration, false);
}

bool ABaseWeapon::CanReload()
{
	return !bIsReloading && CurrentAmmoInClip < AmmoPerClip && CurrentAmmo;
}

void ABaseWeapon::Fire()
{
	if (!CanFire())
	{
		return;
	}

	USkeletalMeshSocket* Socket = MeshComponent->SkeletalMesh->FindSocket(MuzzleSocketName);
	if (Socket == nullptr)
	{
		return;
	}
	WeaponTrace();
	UseAmmo();
}

void ABaseWeapon::UseAmmo()
{
	CurrentAmmoInClip--;
}

void ABaseWeapon::RefillClip()
{
	CurrentAmmo += CurrentAmmoInClip;
	int refillAmount = 0;
	if(CurrentAmmo >= AmmoPerClip)
	{
		refillAmount = AmmoPerClip;
	}
	else
	{
		refillAmount = CurrentAmmo;
	}
	CurrentAmmo-=refillAmount;
	CurrentAmmoInClip = refillAmount;
}

void ABaseWeapon::WeaponTrace()
{

    const FTransform SocketTransform = MeshComponent->GetSocketTransform(MuzzleSocketName);
	const FVector TraceStart = SocketTransform.GetLocation();
	const FVector TraceEnd =  TraceStart + (SocketTransform.GetRotation().GetForwardVector() * Range);
	
	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Green, false, 1.0f, 0, 0.5f);
	
	FHitResult OutHit;
	GetWorld()->LineTraceSingleByChannel(OutHit, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);

	if (OutHit.bBlockingHit)
	{
		DrawDebugBox(GetWorld(), OutHit.ImpactPoint,
		FVector(10, 10, 10), FColor::Magenta, false, 2.0f);
	}
}

bool ABaseWeapon::CanFire() const
{
	return !bIsReloading && CurrentAmmoInClip;
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

