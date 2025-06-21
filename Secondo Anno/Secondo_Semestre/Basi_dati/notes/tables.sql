----------------------- Types: ENUM -----------------------
CREATE TYPE stato_ordine AS ENUM ('ordineto', 'in produzione', 'installazione', 'validato');
CREATE TYPE tipo_cliente AS ENUM ('pubblico', 'privato');
CREATE TYPE tipo_tratta AS ENUM ('merci', 'urbana');

----------------------- TABELLE -----------------------

-- Tabella: cliente
CREATE TABLE IF NOT EXISTS public.cliente (
    id serial NOT NULL,
    tipo tipo_cliente NOT NULL,
    rag_soc character varying(50) NOT NULL,
    cod_fis character varying(16) NOT NULL,
    email character varying(30),
    telefono character varying(15),
    PRIMARY KEY (rag_soc, id),
    CONSTRAINT id_cliente UNIQUE (id),
    CONSTRAINT ragione_sociale UNIQUE (rag_soc)
);

-- Tabella: amministratore
CREATE TABLE IF NOT EXISTS public.amministratore (
    id_amministratore character varying(30) NOT NULL,
    nome character varying(20) NOT NULL,
    cognome character varying(20) NOT NULL,
    email character varying(30),
    telefono character varying(15),
    PRIMARY KEY (id_amministratore)
);

-- Tabella: ordine
CREATE TABLE IF NOT EXISTS public.ordine (
    id serial NOT NULL,
    cliente character varying(50) NOT NULL,
    prezzo smallint NOT NULL,
    quantità integer NOT NULL,
    stato stato_ordine NOT NULL,
    id_amministratore character varying(30),
    PRIMARY KEY (id, cliente),
    CONSTRAINT fk_cliente_ordine FOREIGN KEY (cliente)
        REFERENCES public.cliente(rag_soc),
    CONSTRAINT fk_admin_ordine FOREIGN KEY (id_amministratore)
        REFERENCES public.amministratore(id_amministratore)
);

-- Tabella: modello
CREATE TABLE IF NOT EXISTS public.modello (
    id serial NOT NULL,
    nome character varying(50) NOT NULL,
    carico_assi integer NOT NULL,
    v_max integer NOT NULL,
    tipo_cem character varying(50) NOT NULL,
    peso integer NOT NULL,
    lunghezza integer NOT NULL,
    larghezza integer NOT NULL,
    altezza integer NOT NULL,
    PRIMARY KEY (id),
    CONSTRAINT nome_modello UNIQUE (nome)
);

-- Tabella: componente
CREATE TABLE IF NOT EXISTS public.componente (
    nome character varying(20) NOT NULL,
    descrizione character varying(50),
    quantità integer,
    PRIMARY KEY (nome)
);

-- Tabella: fornitore
CREATE TABLE IF NOT EXISTS public.fornitore (
    id serial NOT NULL,
    nome character varying(30) NOT NULL,
    email character varying(50),
    telefono character varying(15),
    PRIMARY KEY (id),
    CONSTRAINT nome_fornitore UNIQUE (nome)
);

-- Tabella: materiale
CREATE TABLE IF NOT EXISTS public.materiale (
    nome character varying NOT NULL,
    prezzo integer,
    fornitore character varying NOT NULL,
    descrizione character varying,
    PRIMARY KEY (nome),
    CONSTRAINT fk_mat_fornitore FOREIGN KEY (fornitore)
        REFERENCES public.fornitore(nome)
);

-- Tabella: composizione
CREATE TABLE IF NOT EXISTS public.composizione (
    modello_id integer NOT NULL,
    nome_comp character varying NOT NULL,
    quantità integer NOT NULL,
    PRIMARY KEY (modello_id, nome_comp),
    CONSTRAINT fk_comp_modello FOREIGN KEY (modello_id)
        REFERENCES public.modello(id) ON DELETE CASCADE,
    CONSTRAINT fk_comp_componente FOREIGN KEY (nome_comp)
        REFERENCES public.componente(nome)
);