// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasicPlayer.generated.h"

UCLASS()
class PROJECTBD_API ABasicPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		class USpringArmComponent* SpringArm;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		class UWeaponComponent* Weapon;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		class USceneComponent* BulletSpot;

	UFUNCTION(BlueprintImplementableEvent)
		void SpawnBullet();

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUp(float AxisValue);
	void Turn(float AxisValue);
	
	void Sprint();
	void StopSprint();

	void StartFire();
	void StopFire();

	void OnFire();

	

	void StartIronsight();
	void StopIronsight();

	void StartCrouch();

	void CameraViewChange();
	void StopCameraViewChange();

	void ReturnCameraRotator(float DeltaTime);

	float GetPlayerHP();

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float WalkSpeed = 300.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float SprintSpeed = 600.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float PlayerHP = 100.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		uint64 bIsFire : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		uint64 bIsSprint : 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		uint64 bIsIronsight : 1;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "SpringArm");
		FVector NormalSpringArmPosition;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "SpringArm");
		FVector CrouchedSpringArmPosition;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray <TEnumAsByte<EObjectTypeQuery>> TestObjects;

	//카메라 뷰 변환을 하고 있는지 : Alt키를 눌렀는지
	bool IsCameraViewChange = false;

	//카메라 뷰를 원상태로 되돌리고 있는지 : Alt키를 땠는지
	bool IsReturnCameraRotator = false;

	//카메라 뷰의 원래 지점
	FRotator CameraChangeSaveRotator;
};
