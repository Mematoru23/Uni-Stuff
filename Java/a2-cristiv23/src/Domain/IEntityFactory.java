package src.Domain;

public interface IEntityFactory<T extends Entity> {
    T createEntity(String line);
}
