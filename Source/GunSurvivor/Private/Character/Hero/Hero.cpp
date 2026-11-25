// Hungg ne


#include "Character/Hero/Hero.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AHero::AHero()
{
	PrimaryActorTick.bCanEverTick = false;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}
