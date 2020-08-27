// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicPCM.h"
#include "BasicPlayer.h"

ABasicPCM::ABasicPCM() {

}

void ABasicPCM::UpdateCamera(float DeltaTime)
{
	Super::UpdateCamera(DeltaTime);
	//ȭ���̶�� �Ÿ��� ���� ī�޶� ���� ������ �ִ�. FOV��� �Ѵ�.

	//�� ������ �ִ� �÷��̾� ��Ʈ�ѷ��� ������ �� �÷��̾� ��Ʈ�ѷ��� ������ �ִ� ���� ������
	// �� ���� BasicPlayer�� ��ȯ
	ABasicPlayer* Pawn = GetOwningPlayerController()->GetPawn<ABasicPlayer>();

	if (Pawn) {
		//���� �ܾƿ� ����
		float TargetFOV = Pawn->bIsIronsight ? IronsightFOV : NormalFOV;

		//���� FOV : GetFOVAngle()
		//Lerp : �� �� ���̿� ������ ����
		//float ResultFOV = FMath::Lerp(GetFOVAngle(), TargetFOV, 0.5f);

		// �� �� ���̸� ���ϴ� �ð����� �ε巴�� ����
		float ResultFOV = FMath::FInterpTo(GetFOVAngle(), TargetFOV, DeltaTime, 20.0f);
		SetFOV(ResultFOV);
	}
}
