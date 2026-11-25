// Hungg ne

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Hero.generated.h"

class UCameraComponent;
class USpringArmComponent;


UCLASS()
class GUNSURVIVOR_API AHero : public APaperZDCharacter
{
	GENERATED_BODY()
	
public:
	AHero();
	
private:
	/** Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
};
