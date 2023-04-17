

#include "ProjectTFG_U_v1/AnimNotifies/CreatureAttackNotify.h"

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UCreatureAttackNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);


	if (!MeshComp) return;

	AActor* owner = MeshComp->GetOwner();
	if(!owner) return;


	FVector handLocation=MeshComp->GetSocketLocation(HandSocket);

	TArray<AActor*> IgnoredActors;
	IgnoredActors.Add(owner);

	TArray<AActor*> OutActors;

	auto succes=UKismetSystemLibrary::SphereOverlapActors(
		owner,
		handLocation,
		PunchRadius,
		ObjectTypes,
		ACharacter::StaticClass(),
		IgnoredActors,
		OutActors);

	if(succes)
	{
		auto hitactor=OutActors[0];
		if(!hitactor) return;

		UGameplayStatics::ApplyDamage(
			hitactor,
			Damage,
			owner->GetInstigatorController(),
			owner,
			UDamageType::StaticClass());			
			
		
	}
}
