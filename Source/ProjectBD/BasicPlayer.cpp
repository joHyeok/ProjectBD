// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "WeaponComponent.h"

// Sets default values
ABasicPlayer::ABasicPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Weapon = CreateDefaultSubobject<UWeaponComponent>(TEXT("Weapon"));

	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);
	Weapon->SetupAttachment(GetMesh(), TEXT("WeaponSocket"));

	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()));
	//�ϵ��ڵ�
	GetMesh()->SetRelativeRotation(FRotator(0, -90.f, 0));

	//ĳ���� �����Ʈ�� Navmovement�� CanCrouch üũ�ϱ� �ϵ��ڵ�
	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;

	SpringArm->SocketOffset = FVector(0, 40.0f, 88.0f);
	SpringArm->TargetArmLength = 120.f;

	GetCharacterMovement()->CrouchedHalfHeight = GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
}

// Called when the game starts or when spawned
void ABasicPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABasicPlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABasicPlayer::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ABasicPlayer::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ABasicPlayer::Turn);

	PlayerInputComponent->BindAxis(TEXT("CameraView"), this, &ABasicPlayer::CameraView);
	
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ABasicPlayer::Jump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &ABasicPlayer::StopJumping);

	PlayerInputComponent->BindAction(TEXT("Sprint"), IE_Pressed, this, &ABasicPlayer::Sprint);
	PlayerInputComponent->BindAction(TEXT("Sprint"), IE_Released, this, &ABasicPlayer::StopSprint);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ABasicPlayer::StartFire);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Released, this, &ABasicPlayer::StopFire);

	PlayerInputComponent->BindAction(TEXT("Ironsight"), IE_Pressed, this, &ABasicPlayer::StartIronsight);
	PlayerInputComponent->BindAction(TEXT("Ironsight"), IE_Released, this, &ABasicPlayer::StopIronsight);

	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &ABasicPlayer::StartCrouch);
}

void ABasicPlayer::MoveForward(float AxisValue)
{
	//���� ȸ��, ī�޶� ���� ����
	//GetControlRotation().Vector()
	FVector CameraLocation;
	FRotator CameraRotator;
	//��Ʈ�ѷ��� ī�޶��� ������ ������ �ִ�. ī�޶��� ��ġ, ȸ������ �����Ѵ�.
	GetController()->GetPlayerViewPoint(CameraLocation, CameraRotator);

	// ĳ������ �̵��� ī�޶��� �������� �̵���ų���� ��Ʈ�ѷ��� �������� �̵���ų����
	// ���ؾ��Ѵ�. ���������� ���� ȸ������ ���������� �� ������������ ���������μ�
	// �ٸ� ����� ���´�.

	//ī�޶��� �������� �̵��Ѵ�. ���������� yaw�������θ� �̵��Ѵ�.
	//FRotator YawBaseRotation = FRotator(0, CameraRotator.Yaw, 0);

	// ��Ʈ�ѷ��� �������� �̵��Ѵ�.
	FRotator YawBaseRotation = FRotator(0, GetControlRotation().Yaw, 0);

	FVector CameraForward = UKismetMathLibrary::GetForwardVector(YawBaseRotation);

	AddMovementInput(CameraForward, AxisValue);
}

void ABasicPlayer::MoveRight(float AxisValue)
{
	FRotator YawBaseRotation = FRotator(0, GetControlRotation().Yaw, 0);
	FVector CameraRight = UKismetMathLibrary::GetRightVector(YawBaseRotation);
	AddMovementInput(CameraRight, AxisValue);
}

void ABasicPlayer::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void ABasicPlayer::Turn(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void ABasicPlayer::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void ABasicPlayer::StopSprint() {
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void ABasicPlayer::CameraView(float AxisValue)
{

}

void ABasicPlayer::StartFire()
{
	bIsFire = true;
}

void ABasicPlayer::StopFire()
{
	bIsFire = false;
}

void ABasicPlayer::StartIronsight()
{
	bIsIronsight = true;
}

void ABasicPlayer::StopIronsight()
{
	bIsIronsight = false;
}

void ABasicPlayer::StartCrouch()
{
	//�̹� �������� ����� ���� �Լ��̴�.
	// ���� �� �ִ��� �˻��ؼ� �ɰ� �Ͼ�� �� �����Ѵ�.
	if (CanCrouch()) {
		Crouch();
	}
	else {
		UnCrouch();
	}
}

