// Hungg ne


#include "Character/Hero/Hero.h"

#include "PaperSpriteComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AHero::AHero()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	SetRootComponent(CapsuleComp);
	
	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AHero::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

