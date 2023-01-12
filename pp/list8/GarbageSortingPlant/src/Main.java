import polymorphism.GarbageSortingPlant;
import polymorphism.garbages.Garbage;
import polymorphism.garbages.GlassGarbage;
import polymorphism.garbages.PaperGarbage;
import polymorphism.garbages.PlasticGarbage;
import polymorphismless.Trash;
import polymorphismless.TrashSortingPlant;
import polymorphismless.TrashType;

import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    static void runPolymorphismClasses() {
        Garbage p1 = new PlasticGarbage(1, "PET", 420);
        Garbage p2 = new PlasticGarbage(2, "PET_1337", 2137);
        Garbage g1 = new GlassGarbage(3, 1);
        Garbage g2 = new GlassGarbage(4, 130);
        Garbage ppr1 = new PaperGarbage(5, 130);
        Garbage ppr2 = new PaperGarbage(6, 420);
        GarbageSortingPlant gsp = new GarbageSortingPlant();
        gsp.sort(new ArrayList<>(Arrays.asList(p1, p2, g1, g2, ppr1, ppr2)));
        System.out.println(gsp.getGlassGarbages());
        System.out.println(gsp.getPaperGarbages());
        System.out.println(gsp.getPlasticGarbages());
    }

    static void runPolymorphismlessClasses() {
        Trash p1 = new Trash(TrashType.PLASTIC, "PET", 1, 420);
        Trash p2 = new Trash(TrashType.PLASTIC, "PET", 1, 450);
        Trash g1 = new Trash(TrashType.GLASS, 1, 450.0);
        Trash g2 = new Trash(TrashType.GLASS, 1, 450.0);
        Trash ppr1 = new Trash(TrashType.PAPER, 450, 45);
        Trash ppr2 = new Trash(TrashType.PAPER, 450, 45);
        TrashSortingPlant gsp = new TrashSortingPlant();
        gsp.sort(new ArrayList<>(Arrays.asList(p1, p2, g1, g2, ppr1, ppr2)));
        System.out.println(gsp.getGlassTrashes());
        System.out.println(gsp.getPaperTrashes());
        System.out.println(gsp.getPlasticTrashes());
    }

    public static void main(String[] args) {
        System.out.println("POLYMORPHISM");
        runPolymorphismClasses();
        System.out.println("POLYMORPHISMLESS");
        runPolymorphismlessClasses();
    }
}