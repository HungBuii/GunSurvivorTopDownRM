// Hungg ne

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
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
	
protected:
	virtual void BeginPlay() override;
	
public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	/** Move action */
	void Move(const FInputActionValue& Value);
	
private:
	/** Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	/** Input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* InputMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;
	
	/** Speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "Speed", meta = (AllowPrivateAccess = "true"))
	float Speed = 100.f;
};
