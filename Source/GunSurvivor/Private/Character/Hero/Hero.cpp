// Hungg ne


#include "Character/Hero/Hero.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/GunSurvivorPlayerController.h"

AHero::AHero()
{
	PrimaryActorTick.bCanEverTick = false;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void AHero::BeginPlay()
{
	Super::BeginPlay();
	
	AGunSurvivorPlayerController* GunSurvivorPlayerController = Cast<AGunSurvivorPlayerController>(Controller);
	if (GunSurvivorPlayerController)
	{
		
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
														(GunSurvivorPlayerController->GetLocalPlayer());

		if (Subsystem)
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
}

void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AHero::Move);
	}
}

void AHero::Move(const FInputActionValue& Value)
{
	FVector2D MoveActionValue = Value.Get<FVector2D>();
	GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::White, MoveActionValue.ToString());
	
	if (abs(MoveActionValue.Y) > 0)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector DistanceToMove = GetActorUpVector() * Speed * MoveActionValue.Y * GetWorld()->GetDeltaSeconds();
		FVector NewLocation = CurrentLocation + DistanceToMove;
		SetActorLocation(NewLocation);
	}
	
	if (abs(MoveActionValue.X) > 0)
	{
		UpdateDirection(MoveActionValue.X);
		
		FVector CurrentLocation = GetActorLocation();
		FVector DistanceToMove = GetActorForwardVector() * Speed * GetWorld()->GetDeltaSeconds();
		FVector NewLocation = CurrentLocation + DistanceToMove;
		SetActorLocation(NewLocation);
	}
	
}

void AHero::UpdateDirection(float _MoveDirection)
{
	FRotator CurrentRotation = Controller->GetControlRotation();
	
	if (_MoveDirection > 0.f)
	{
		if (CurrentRotation.Yaw != 0.f)
		{
			Controller->SetControlRotation(FRotator(CurrentRotation.Pitch, 0.f, CurrentRotation.Roll));
		}
	}
	
	if (_MoveDirection < 0.f)
	{
		if (CurrentRotation.Yaw != 180.f)
		{
			Controller->SetControlRotation(FRotator(CurrentRotation.Pitch, 180.f, CurrentRotation.Roll));
		}
	}
}
