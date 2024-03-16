package Repo;

import Domain.Entity;

import java.io.IOException;
import java.util.Collection;

public interface IRepo<T extends Entity> extends Iterable<T> {
    void add(T entity) throws DuplicateEntityException, IOException;
    void remove(int id) throws Exception;
    void modify(T entity) throws Exception;
    T findById(int id);
    Collection<T> getAll();
}
