datatype Planeta  = Mercurio | Venus | Terra | Marte | Jupiter | Saturno | Urano | Netuno;

fun planetAge (m, p) =
                       if p = Mercurio then round(real (88 * m) / 12.0)
                       else if p = Venus then round(real (225 * m) / 12.0)
                       else if p = Terra then round(real (365 * m) / 12.0)
                       else if p = Marte then round(real (687 * m) / 12.0)
                       else if p = Jupiter then round(real (4332 * m) / 12.0)
                       else if p = Saturno then round(real (10760 * m) / 12.0)
                       else if p = Urano then round(real (30681 * m) / 12.0)
                       else if p = Netuno then round(real (60190 * m) / 12.0)
                       else 0;

planetAge (24, Jupiter);