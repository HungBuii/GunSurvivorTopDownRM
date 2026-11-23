// Hungg ne

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Hero.generated.h"

class UPaperSpriteComponent;
class UCapsuleComponent;

UCLASS()
class GUNSURVIVOR_API AHero : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHero();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	/** Collision */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UCapsuleComponent* CapsuleComp;
	
	/** Sprite */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	UPaperSpriteComponent* Sprite;
};
