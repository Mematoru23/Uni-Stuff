package src.Service;

import src.Repo.DuplicateEntityException;
import src.Repo.IRepo;
import src.Domain.Cake;

import java.util.Collection;

public class CakeService {
    IRepo<Cake> repository;

    public CakeService(IRepo<Cake> repository) {
        this.repository = repository;
    }

    public void addCake(int id, String cakeType) throws DuplicateEntityException {
        repository.add(new Cake(id, cakeType));
    }

    public void removeCake(int id) throws Exception {
        repository.remove(id);
    }

    public void modifyCake(int id, String cakeType) throws Exception
    {
        repository.modify(new Cake(id, cakeType));
    }

    public Collection<Cake> getAll()
    {
        return repository.getAll();
    }
}
