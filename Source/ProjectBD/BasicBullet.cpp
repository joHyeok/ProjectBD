// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicBullet.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "BasicPlayer.h"

// Sets default values
ABasicBullet::ABasicBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));

	RootComponent = Sphere;
	Body->SetupAttachment(RootComponent);

	Body->SetRelativeLocation(FVector(-5.f, 0, 0));
	Body->SetRelativeRotation(FRotator(0, -90.f, 0));

	Tags.Add(TEXT("Bulltet"));
}

// Called when the game starts or when spawned
void ABasicBullet::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ABasicBullet::ProcessBeginOverlap);
}

// Called every frame
void ABasicBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasicBullet::ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	TArray<AActor*> Output;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ABasicPlayer::StaticClass(), TEXT("Target"), Output);
	UE_LOG(LogClass, Warning, TEXT("Bullet Output Num : %d"), Output.Num());
	if (OtherActor->ActorHasTag(TEXT("Target")))
	{
		OtherActor->Destroy();

		AMyGameModeBase* GameMode = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
		GameMode->CheckGameRule();
	}
	
}

