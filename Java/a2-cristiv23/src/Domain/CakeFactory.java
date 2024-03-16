package src.Domain;

public class CakeFactory implements IEntityFactory<Cake>{
    @Override
    public Cake createEntity(String line) {
        int id = Integer.parseInt(line.split(",")[0]);
        String type = line.split(",")[1];

        return new Cake(id, type);
    }
}
