#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned

/* MyX = MyVector.X;
	MyVector.Y = MyX + 1;
	FVector LocalVector = MyVector;

	LocalVector.Z = LocalVector.Z + 1;

	MyVector.Y = MyVector.Y + 1;

	SetActorLocation(LocalVector); */

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{

	// Move platform forwards
		// Get current location
	FVector CurrentLocation = GetActorLocation();
		// Add vector to that location
	CurrentLocation = CurrentLocation + PlatformVelocity *DeltaTime;
		// Set the location
	SetActorLocation(CurrentLocation);
	// Send platform back if gone too far
		//Check how far we've moved
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		//Reverse direction of motion if gone too far
	if(DistanceMoved > MoveDistance)
	{

		float OverShoot = DistanceMoved - MoveDistance;
		FString Name = GetName();
		UE_LOG(LogTemp, Display, TEXT("%s Platform overshot by = %f"), *Name, OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;

	}

}
void AMovingPlatform::RotatePlatform(float DeltaTime)
{

FString Name2 = "siemiouuuuuuuu";
UE_LOG(LogTemp, Display, TEXT("%s Rotating..."), *GetName());

}
