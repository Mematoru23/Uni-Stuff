package src.Repo;

import src.Domain.Entity;

import java.util.Collection;

public interface IRepo<T extends Entity> extends Iterable<T> {
    void add(T entity) throws DuplicateEntityException;
    void remove(int id) throws Exception;
    void modify(T entity) throws Exception;
    T findById(int id);
    Collection<T> getAll();
}
