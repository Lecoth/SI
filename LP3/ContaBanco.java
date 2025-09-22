/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package org.openjfx.contabanco;

/**
 *
 * @author letic
 */
public class ContaBanco {

    public static void main(String[] args) {
        Conta p1 = new Conta();
        p1.setNumConta(1111);
        p1.setDono("Leticia");
        p1.abrirConta("CC");
        
        Conta p2 = new Conta();
        p2.setNumConta(2222);
        p2.setDono("Consuelo");
        p2.abrirConta("CP");
        
        p1.depositar(100);
        p2.depositar(500);
        
        p1.estadoAtual();
        p2.estadoAtual();
        
    }
}
