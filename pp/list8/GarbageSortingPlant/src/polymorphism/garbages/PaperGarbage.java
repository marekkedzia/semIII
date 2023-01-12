package polymorphism.garbages;

public class PaperGarbage extends Garbage {
    private int grammage;

    public PaperGarbage(int weightInGrams, int grammage) {
        super(weightInGrams);
        this.grammage = grammage;
    }

    @Override
    public String toString() {
        return "polymorphism.garbages.PaperGarbage{" +
                "grammage=" + grammage +
                '}';
    }
}
