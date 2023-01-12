package polymorphism.garbages;

public abstract class Garbage {
    public Garbage(int weightInGrams) {
        if (weightInGrams <= 0)
            throw new Error("Weight must be positive Integer");

        this.weightInGrams = weightInGrams;
    }

    int weightInGrams;
}
