package com.example.lab444.Service;


import Domain.Cake;
import com.example.lab444.Repository.DuplicateEntityException;
import com.example.lab444.Repository.EntityNotFoundException;
import com.example.lab444.Repository.IRepository;
import com.example.lab444.Repository.RepositoryException;
import com.example.lab444.Repository.IRepository;

import java.util.Collection;

public class CakeService {
    IRepository<Cake> repository;

    public CakeService(IRepository<Cake> repository){
        this.repository = repository;
    }

    public void add(int id, String type) throws DuplicateEntityException, RepositoryException {
        repository.add(new Cake(id,type));
    }

    public void delete(int id) throws EntityNotFoundException, RepositoryException {
        repository.remove(id);
    }

    public Cake find(int id){
        return repository.find(id);
    }

    public void update(int id, String type) throws EntityNotFoundException, RepositoryException {
        if(find(id)==null)
            throw new EntityNotFoundException("Entity doesn t exist!");
        //find(id).setType(type);
        repository.update(id, new Cake(id,type));
    }
    public Collection<Cake> getAll() throws RepositoryException {
        return repository.getAll();
    }
}

